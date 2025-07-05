func simplifiedFractions(n int) []string {
    arr:= []string{}
    for i:=1; i<=n; i++{
        for j:=1; j<=i; j++{
            if  j < i && gcd(i,j) == 1{
                frac:=fraction(j,i)
                arr=append(arr,frac)
            }
        }
    }
    return arr 
}
//greatest common divisor
func gcd(a,b int ) int{
    for b != 0 {
       a , b = b , a%b
    }
    return a
}
// numerator and denominator to form fraction
func fraction(a,b int) string{
    numerator:=""
    denominator:=""
    for ;a > 0; a /= 10 {
        numerator = string( byte(a%10)+'0') + numerator
    }
    for ;b>0; b /= 10 {
        denominator = string(byte(b%10)+'0') + denominator
    }
    return numerator+"/"+denominator
}