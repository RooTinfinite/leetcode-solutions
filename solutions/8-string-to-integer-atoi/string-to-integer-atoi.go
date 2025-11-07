func myAtoi(input string) int {
    sign := 1
    result := 0
    index := 0
    n := len(input)

    INT_MAX := int(math.Pow(2, 31) - 1)
    INT_MIN := -int(math.Pow(2, 31))

    for index < n && input[index] == ' ' {
        index++
    }

    if index < n && input[index] == '+' {
        sign = 1
        index++
    } else if index < n && input[index] == '-' {
        sign = -1
        index++
    }

    for index < n && input[index] >= '0' && input[index] <= '9' {
        digit := int(input[index] - '0')

        if result > INT_MAX/10 || (result == INT_MAX/10 && digit > INT_MAX%10) {
            if sign == 1 {
                return INT_MAX
            }
            return INT_MIN
        }

        result = 10*result + digit
        index++
    }

    return sign * result
}