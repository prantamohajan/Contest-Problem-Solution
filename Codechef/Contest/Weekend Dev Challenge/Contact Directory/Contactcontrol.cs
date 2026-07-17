using Microsoft.AspNetCore.Mvc;
using System;
using System.Collections.Generic;
using System.Linq;
using ContactDirectory.Models;

namespace ContactDirectory.Controllers
{
    [ApiController]
    // TODO 1: Set the route for this controller
    [Route("api/[controller]")]
    // TODO 2: Inherit from the ASP.NET Core base controller class
    public class ContactsController : ControllerBase
    {
        // Static list acts as our in-memory database
        private static readonly List<Contact> _contacts = new List<Contact>();

        // TODO 3: Add the correct HTTP POST route attribute
        [HttpPost]
        // TODO 4: Bind the incoming JSON request body
        public IActionResult CreateContact([FromBody] Contact newContact)
        {
            // TODO 5: Validate the incoming payload
            if (string.IsNullOrWhiteSpace(newContact.Name) || string.IsNullOrWhiteSpace(newContact.PhoneNumber))
            {
                return BadRequest("Name and Phone Number are required.");
            }

            // TODO 6: Sanitize phone number by removing "-", " ", "+"
            string sanitizedPhone = newContact.PhoneNumber
                .Replace("-", "")
                .Replace(" ", "")
                .Replace("+", "");

            // TODO 7: Validate the sanitized phone number
            if (sanitizedPhone.Length < 7 || sanitizedPhone.Length > 15 || !sanitizedPhone.All(char.IsDigit))
            {
                return BadRequest("Invalid phone number format.");
            }

            // TODO 8: Check for duplicate phone number using LINQ .Any()
            bool isDuplicate = _contacts.Any(c => c.PhoneNumber == newContact.PhoneNumber);
            if (isDuplicate)
            {
                return Conflict("A contact with this phone number already exists.");
            }

            // Persistence Logic (Provided)
            newContact.Id = Guid.NewGuid();
            _contacts.Add(newContact);

            // TODO 9: Return a Created(...) response
            return Created(
                $"/api/contacts/{newContact.Id}",
                newContact
            );
        }

        // TODO 10: Add the correct HTTP GET route attribute
        [HttpGet]
        public IActionResult GetContacts(
            // TODO 11: Bind all parameters below directly from the query string
            [FromQuery] string? searchName,
            [FromQuery] string? tag,
            [FromQuery] int page = 1,
            [FromQuery] int pageSize = 5
        )
        {
            // Start with the full collection as a queryable source
            var query = _contacts.AsQueryable();

            // TODO 12: Apply the Name filter (Case-insensitive)
            if (!string.IsNullOrWhiteSpace(searchName))
            {
                query = query.Where(c => c.Name.Contains(searchName, StringComparison.OrdinalIgnoreCase));
            }

            // TODO 13: Apply the Tag filter (Case-insensitive)
            if (!string.IsNullOrWhiteSpace(tag))
            {
                query = query.Where(c => c.Tags.Contains(tag, StringComparer.OrdinalIgnoreCase));
            }

            // সেভ করে রাখি টোটাল ম্যাচের সংখ্যা পেজিনেশন করার আগে
            int totalMatches = query.Count();

            // TODO 14: Implement pagination logic
            int skipAmount = (page - 1) * pageSize;
            var paginatedResults = query.Skip(skipAmount).Take(pageSize).ToList();

            // TODO 15: Return Ok(...) with anonymous object
            return Ok(new
            {
                CurrentPage = page,
                PageSize = pageSize,
                TotalMatches = totalMatches,
                Data = paginatedResults
            });
        }
    }
}