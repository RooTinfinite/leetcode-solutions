class Solution {
    public int numUniqueEmails(String[] emails) {
        Set<String> uniqueEmails = new HashSet<>();
        
        for (String email : emails) {
            String[] parts = email.split("@");
            String local = parts[0];
            String domain = parts[1];
            
            local = local.split("\\+")[0];
            local = local.replace(".", "");
            
            uniqueEmails.add(local + "@" + domain);
        }
        
        return uniqueEmails.size();
    }
}
