using Microsoft.AspNetCore.Mvc;
using System;
using System.Collections.Concurrent;
using System.Linq;
using VirtualDrive.Models;

namespace VirtualDrive.Controllers
{
    [ApiController]
    // TODO 1: Inherit from ControllerBase
    public class DriveController : ControllerBase
    {
        // Thread-safe in-memory database
        private static readonly ConcurrentDictionary<Guid, FileRecord> _driveDatabase =
            new ConcurrentDictionary<Guid, FileRecord>();

        // Allowed file types
        private static readonly string[] _allowedExtensions =
        {
            ".txt",
            ".pdf",
            ".png",
            ".jpg",
            ".docx"
        };

        // Maximum allowed upload size (10 MB)
        private const long MaxFileSizeBytes = 10 * 1024 * 1024;


        // TODO 2: Add the correct HTTP POST route attribute for "api/upload"
        [HttpPost("api/upload")]
        // TODO 3: Bind the incoming JSON request body to the 'request' parameter using [FromBody]
        public IActionResult UploadFile([FromBody] UploadRequest request)
        {
            // TODO 4: Validate the incoming payload.
            if (request == null || string.IsNullOrWhiteSpace(request.FileName) || string.IsNullOrWhiteSpace(request.Extension))
            {
                return BadRequest("File name and extension are required.");
            }

            // TODO 5: Validate the file size.
            if (request.SizeInBytes <= 0 || request.SizeInBytes > MaxFileSizeBytes)
            {
                return BadRequest("Invalid file size. Size must be greater than 0 and up to 10 MB.");
            }

            // TODO 6: Normalize the extension:
            string normalizedExtension = request.Extension.ToLower().Trim();

            // Then validate whether _allowedExtensions contains this extension.
            if (!_allowedExtensions.Contains(normalizedExtension))
            {
                return BadRequest("File extension not allowed.");
            }

            // TODO 7: Create a new FileRecord object.
            var newFile = new FileRecord
            {
                Id = Guid.NewGuid(),
                FileName = request.FileName,
                Extension = normalizedExtension,
                SizeInBytes = request.SizeInBytes,
                UploadedAt = DateTime.UtcNow
            };

            // TODO 8: Save the new record into _driveDatabase using newFile.Id as the key.
            _driveDatabase[newFile.Id] = newFile;

            // TODO 9: Return a Created(...) response.
            return Created($"/api/files/{newFile.Id}", newFile);
        }


        // TODO 10: Add the correct HTTP GET route attribute for "api/files"
        [HttpGet("api/files")]
        public IActionResult GetAllFiles()
        {
            // TODO 11: Retrieve all stored files, convert to a List, and return Ok(...)
            var filesList = _driveDatabase.Values.ToList();
            return Ok(filesList);
        }


        // TODO 12: Add the correct HTTP GET route attribute for "api/files/{id}"
        [HttpGet("api/files/{id}")]
        public IActionResult GetFileById(string id)
        {
            // TODO 13: Safely parse the incoming string 'id' into a Guid. (Provided)
            if (!Guid.TryParse(id, out Guid fileId))
            {
                return BadRequest(new { error = "Invalid file ID format." });
            }

            // TODO 14: Check whether _driveDatabase contains this fileId.
            bool fileExists = _driveDatabase.ContainsKey(fileId);

            // TODO 15: If the file does NOT exist, return NotFound(...)
            if (!fileExists)
            {
                return NotFound("File not found.");
            }

            // TODO 16: Retrieve the FileRecord object and return Ok(fileRecord)
            var fileRecord = _driveDatabase[fileId];
            return Ok(fileRecord);
        }


        // TODO 17: Add the correct HTTP DELETE route attribute for "api/files/{id}"
        [HttpDelete("api/files/{id}")]
        public IActionResult DeleteFile(string id)
        {
            // TODO 18: Safely parse the incoming string 'id' into a Guid. (Provided)
            if (!Guid.TryParse(id, out Guid fileId))
            {
                return BadRequest(new { error = "Invalid file ID format." });
            }

            // TODO 19: Check whether _driveDatabase contains this fileId.
            bool fileExists = _driveDatabase.ContainsKey(fileId);

            // TODO 20: If the file does NOT exist, return NotFound(...)
            if (!fileExists)
            {
                return NotFound("File not found.");
            }

            // TODO 21: Remove the file from _driveDatabase using TryRemove(...)
            _driveDatabase.TryRemove(fileId, out _);

            // TODO 22: Return NoContent() representing HTTP 204
            return NoContent();
        }
    }
}