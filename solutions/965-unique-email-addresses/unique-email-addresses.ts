function numUniqueEmails(emails: string[]): number {
    const uniqueEmails = new Set<string>();
    
    for (const email of emails) {
        const [local, domain] = email.split('@');
        const cleanLocal = local.split('+')[0].replace(/\./g, '');
        uniqueEmails.add(`${cleanLocal}@${domain}`);
    }
    
    return uniqueEmails.size;
}
