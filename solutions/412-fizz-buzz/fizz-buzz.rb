def fizz_buzz(n)
    res = []
    (1..n).each do |i|
        if i % 3 == 0 && i % 5 == 0
            res.push("FizzBuzz")
        elsif i % 3 == 0
            res.push("Fizz")
        elsif i % 5 == 0
            res.push("Buzz")
        else
            res.push(i.to_s)
        end
    end
    res
end