using System;

namespace UrlShortener.Models
{
    public class UrlMapping
    {
        // TODO 1: Create a public string property named ShortCode
        public string ShortCode { get; set; } = string.Empty;

        // TODO 2: Create a public string property named LongUrl
        public string LongUrl { get; set; } = string.Empty;
    }
}