// class FoodRatings {
// public:
//     vector<string> foods;
//     vector<string> cuisines;
//     vector<int> ratings;
//     FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
//         this->foods = foods;
//         this->cuisines = cuisines;
//         this->ratings = ratings;
//     }
    
//     void changeRating(string food, int newRating) {
//         for (int i=0;i<foods.size();i++){
//             if (foods[i]==food){
//                 ratings[i]=newRating;
//             }
//         }
//     }
    
//     string highestRated(string cuisine) {
//         int maxi = -1;
//         string bestFood = "";
        
//         for (int i = 0; i < cuisines.size(); i++) {
//             if (cuisines[i] == cuisine) {
//                 if (ratings[i] > maxi) {
//                     maxi = ratings[i];
//                     bestFood = foods[i];
//                 }
//                 else if (ratings[i] == maxi && foods[i] < bestFood) {
//                     bestFood = foods[i];
//                 }
//             }
//         }
//         return bestFood;
//     }
// };

// /**
//  * Your FoodRatings object will be instantiated and called as such:
//  * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
//  * obj->changeRating(food,newRating);
//  * string param_2 = obj->highestRated(cuisine);
//  */

// class FoodRatings {
// public:
//     vector<string> foods;
//     vector<string> cuisines;
//     vector<int> ratings;
//     unordered_map<string, int> foodIndex; 

//     FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
//         this->foods = foods;
//         this->cuisines = cuisines;
//         this->ratings = ratings;

//         for (int i = 0; i < foods.size(); i++) {
//             foodIndex[foods[i]] = i; 
//         }
//     }
    
//     void changeRating(string food, int newRating) {
//         int idx = foodIndex[food]; 
//         ratings[idx] = newRating;
//     }
    
//     string highestRated(string cuisine) {
//         int maxi = -1;
//         string bestFood = "";
        
//         for (int i = 0; i < cuisines.size(); i++) {
//             if (cuisines[i] == cuisine) {
//                 if (ratings[i] > maxi) {
//                     maxi = ratings[i];
//                     bestFood = foods[i];
//                 }
//                 else if (ratings[i] == maxi && foods[i] < bestFood) {
//                     bestFood = foods[i];
//                 }
//             }
//         }
//         return bestFood;
//     }
// };

class FoodRatings {
public:

    unordered_map<string, string> foodToCuisine;     
    unordered_map<string, int> foodToRating;         
    unordered_map<string, set<pair<int, string>>> cuisineFoods; 

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            string food = foods[i];
            string cuisine = cuisines[i];
            int rating = ratings[i];

            foodToCuisine[food] = cuisine;
            foodToRating[food] = rating;
            cuisineFoods[cuisine].insert({-rating, food}); 
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = foodToCuisine[food];
        int oldRating = foodToRating[food];


        cuisineFoods[cuisine].erase({-oldRating, food});
        
        cuisineFoods[cuisine].insert({-newRating, food});
        
        foodToRating[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        // Top food is at begin()
        return cuisineFoods[cuisine].begin()->second;
    }
};