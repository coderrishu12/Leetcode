class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drinkable     = 0;
        int non_drinkable = 0;
        int sum=numBottles;
        
        while(numBottles >= numExchange){
            drinkable = numBottles / numExchange;
            non_drinkable = numBottles % numExchange;
            sum+=drinkable;
            numBottles = drinkable + non_drinkable;
            
            if (numBottles < numExchange) {
            break;  // If remaining bottles are less than numExchange, stop the loop
            }
        }
        return sum;
    }
};