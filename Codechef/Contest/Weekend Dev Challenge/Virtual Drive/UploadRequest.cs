namespace VirtualDrive.Models
{
    // Request model used for incoming upload payloads
    public class UploadRequest
    {
        // TODO 1: Create a public string property named FileName initialized to string.Empty
        public string FileName { get; set; } = string.Empty;

        // TODO 2: Create a public string property named Extension initialized to string.Empty
        public string Extension { get; set; } = string.Empty;

        // TODO 3: Create a public long property named SizeInBytes initialized to 0
        public long SizeInBytes { get; set; } = 0;
    }
}