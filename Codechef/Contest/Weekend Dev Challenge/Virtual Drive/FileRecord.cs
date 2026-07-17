using System;

namespace VirtualDrive.Models
{
    // Database entity representing a stored virtual file
    public class FileRecord
    {
        // TODO 1: Create a public Guid property named Id
        public Guid Id { get; set; }

        // TODO 2: Create a public string property named FileName initialized to string.Empty
        public string FileName { get; set; } = string.Empty;

        // TODO 3: Create a public string property named Extension initialized to string.Empty
        public string Extension { get; set; } = string.Empty;

        // TODO 4: Create a public long property named SizeInBytes initialized to 0
        public long SizeInBytes { get; set; } = 0;

        // TODO 5: Create a public DateTime property named UploadedAt
        public DateTime UploadedAt { get; set; }
    }
}