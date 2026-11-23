type ProductOfNumbers struct {
    products []int
}

func Constructor() ProductOfNumbers {
    return ProductOfNumbers{
        products: []int{1},
    }
}

func (this *ProductOfNumbers) Add(num int) {
    if num == 0 {
        this.products = []int{1}
    } else {
        last := this.products[len(this.products)-1]
        this.products = append(this.products, last*num)
    }
}

func (this *ProductOfNumbers) GetProduct(k int) int {
    n := len(this.products)
    if k >= n {
        return 0
    }
    return this.products[n-1] / this.products[n-1-k]
}