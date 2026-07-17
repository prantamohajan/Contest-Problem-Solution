using System;
using System.Collections.Generic;

namespace ContactDirectory.Models
{
    public class Contact
    {
        // TODO 1:
        public Guid Id { get; set; }

        // TODO 2:
        public string Name { get; set; } = String.Empty;

        // TODO 3:
        public string PhoneNumber { get; set; } = String.Empty;

        // TODO 4:
        public List<string> Tags { get; set; } = new List<string>();
    }
}