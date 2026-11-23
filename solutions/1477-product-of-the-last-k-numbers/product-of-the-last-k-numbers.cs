public class ProductOfNumbers {
    private List<int> products;

    public ProductOfNumbers() {
        products = new List<int> { 1 };
    }
    
    public void Add(int num) {
        if (num == 0) {
            products.Clear();
            products.Add(1);
        } else {
            products.Add(products[products.Count - 1] * num);
        }
    }
    
    public int GetProduct(int k) {
        int n = products.Count;
        if (k >= n) {
            return 0;
        }
        return products[n - 1] / products[n - 1 - k];
    }
}