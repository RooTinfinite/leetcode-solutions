use std::collections::HashSet;

impl Solution {
    pub fn num_unique_emails(emails: Vec<String>) -> i32 {
        let mut unique_emails = HashSet::new();
        
        for email in emails {
            let parts: Vec<&str> = email.split('@').collect();
            let mut local = parts[0].to_string();
            let domain = parts[1].to_string();
            
            if let Some(plus_idx) = local.find('+') {
                local.truncate(plus_idx);
            }
            
            local = local.replace(".", "");
            unique_emails.insert(format!("{}@{}", local, domain));
        }
        
        unique_emails.len() as i32
    }
}
