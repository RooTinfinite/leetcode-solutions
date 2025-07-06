class Solution {
public:
    string reformatDate(string date) {
        static unordered_map<string, string> months = {
            {"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"},
            {"May", "05"}, {"Jun", "06"}, {"Jul", "07"}, {"Aug", "08"},
            {"Sep", "09"}, {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}
        };

        string day, month, year;
        int i = 0;
        while (isdigit(date[i])) day += date[i++];
        if (day.size() == 1) day = '0' + day;

        i += 3;
        month = date.substr(i, 3);

        i += 4;
        year = date.substr(i, 4);

        return year + '-' + months[month] + '-' + day;
    }
};