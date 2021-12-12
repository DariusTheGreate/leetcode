int maxProfit(int* prices, int pricesSize){
    int minPrice = 1000000;
    int bestProfit = -100000;
    for(int i = 0; i < pricesSize; i++){
        if(prices[i] < minPrice){
            minPrice = prices[i];
        }
        if(prices[i] - minPrice > bestProfit)
            bestProfit = prices[i] - minPrice;
    }
    
    return bestProfit;
}