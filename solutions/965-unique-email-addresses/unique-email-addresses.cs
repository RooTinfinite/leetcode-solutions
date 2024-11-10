public class Solution {
    public int NumUniqueEmails(string[] emails) {
        var uniqueEmails = new HashSet<string>();
        
        foreach (string email in emails) {
            string[] parts = email.Split('@');
            string local = parts[0];
            string domain = parts[1];
            
            local = local.Split('+')[0];
            local = local.Replace(".", "");
            
            uniqueEmails.Add($"{local}@{domain}");
        }
        
        return uniqueEmails.Count;
    }
}
