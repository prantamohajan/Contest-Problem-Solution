using Microsoft.AspNetCore.Mvc;
using System;
using System.Collections.Concurrent;
using System.Linq; 
using UrlShortener.Models;

namespace UrlShortener.Controllers
{
    [ApiController]
    // TODO 1: Inherit from ControllerBase for Web APIs.
    public class UrlController : ControllerBase
    {
        // Thread-safe in-memory storage acting as our URL database
        private static readonly ConcurrentDictionary<string, UrlMapping> _urlDatabase = new ConcurrentDictionary<string, UrlMapping>();

        private static readonly Random _random = new Random();

        private const string CharacterPool = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";


        // TODO 2: Add the correct HTTP POST route attribute for "api/shorten"
        [HttpPost("api/shorten")]
        // TODO 3: Bind the incoming JSON request body to the 'request' parameter using [FromBody]
        public IActionResult ShortenUrl([FromBody] ShortenRequest request)
        {
            // TODO 4: Validate the incoming payload.
            if (request == null || string.IsNullOrWhiteSpace(request.LongUrl))
            {
                return BadRequest("Invalid request. LongUrl is required.");
            }

            // URL normalization (Provided)
            string destinationUrl = request.LongUrl.Trim();

            if (!destinationUrl.StartsWith("http://") && !destinationUrl.StartsWith("https://"))
            {
                destinationUrl = "https://" + destinationUrl;
            }

            // Generate a unique shortcode (Provided)
            string shortCode = GenerateUniqueShortCode();


            // TODO 5: Create a new UrlMapping object.
            var mapping = new UrlMapping
            {
                ShortCode = shortCode,
                LongUrl = destinationUrl
            };

            // TODO 6: Save the mapping into '_urlDatabase' using 'shortCode' as the key.
            _urlDatabase[shortCode] = mapping;

            // TODO 7: Return a Created(...) response.
            return Created($"/{shortCode}", mapping);
        }


        // TODO 8: Add the correct HTTP GET route attribute to capture a dynamic "{code}" route parameter.
        [HttpGet("{code}")]
        public IActionResult RedirectToLongUrl(string code)
        {
            // TODO 9: Validate the incoming shortcode.
            if (string.IsNullOrEmpty(code))
            {
                return BadRequest("Invalid shortcode.");
            }

            // TODO 10: Safely retrieve the mapping.
            if (!_urlDatabase.TryGetValue(code, out var mapping))
            {
                return NotFound("Shortcode not found.");
            }

            // TODO 11: Return a Redirect(...) response pointing to mapping.LongUrl.
            return Redirect(mapping.LongUrl);
        }


        // Core Helper Method
        private string GenerateUniqueShortCode()
        {
            string code;

            do
            {
                // TODO 12: Create a character array named 'randomChars' with a size of 6.
                char[] randomChars = new char[6];

                // TODO 13: Create a loop that runs exactly 6 times.
                for (int i = 0; i < 6; i++)
                {
                    // TODO 14: Generate a random integer.
                    int randomIndex = _random.Next(0, CharacterPool.Length);

                    // TODO 15: Select a character from CharacterPool and store it inside randomChars[i].
                    randomChars[i] = CharacterPool[randomIndex];
                }

                // TODO 16: Convert the completed character array into a string and assign it to 'code'.
                code = new string(randomChars);

            }
            while (_urlDatabase.ContainsKey(code));

            return code;
        }
    }
}