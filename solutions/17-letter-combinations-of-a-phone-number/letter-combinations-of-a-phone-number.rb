def letter_combinations(digits)
    @res = []

    @digits = digits
    @digitToChar = {
        "2" => "abc",
        "3" => "def",
        "4" => "ghi",
        "5" => "jkl",
        "6" => "mno",
        "7" => "qprs",
        "8" => "tuv",
        "9" => "wxyz",
    }

    def backtrack(i, curStr)
        if curStr.length == @digits.length
            @res.push(curStr)
            return
        end

        for c in @digitToChar[@digits[i]].chars
            backtrack(i + 1, curStr + c)
        end
    end

    backtrack(0, "") if @digits && @digits != ""

    @res
end