namespace UrlShortener.Models
{
    // Request model used for incoming URL payloads
    public class ShortenRequest
    {
        // TODO 1: Create a public string property named LongUrl initialized to string.Empty
        public string LongUrl { get; set; } = string.Empty;
    }
}