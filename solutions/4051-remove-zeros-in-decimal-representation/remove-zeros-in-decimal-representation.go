package main

import (
    "fmt"
    "strings"
)

func removeZeros(n int64) int64 {
    str := strings.ReplaceAll(fmt.Sprint(n), "0", "")
    var result int64
    fmt.Sscan(str, &result)
    return result
}