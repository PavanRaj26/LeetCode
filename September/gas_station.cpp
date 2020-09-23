class Solution {
public:
    struct PetrolPump  
{      
    int petrol;  
    int distance;  
    PetrolPump(int petrol,int distance) : petrol(petrol),distance(distance) {}
};  
  
// The function returns starting point if there is a possible solution,  
// otherwise returns -1  
int printTour(vector<PetrolPump> arr, int n)  
{  
    // Consider first petrol pump as a starting point  
    int start = 0;  
    int end = 1;  
  
    int curr_petrol = arr[start].petrol - arr[start].distance;  
    end = (end) % n;
    /* Run a loop while all petrol pumps are not visited.  
    And we have reached first petrol pump again with 0 or more petrol */
    while (end != start || curr_petrol < 0)  
    {  
        // If curremt amount of petrol in truck becomes less than 0, then  
        // remove the starting petrol pump from tour  
        while (curr_petrol < 0 && start != end)  
        {  
            // Remove starting petrol pump. Change start  
            curr_petrol -= arr[start].petrol - arr[start].distance;  
            start = (start + 1) % n;  
  
            // If 0 is being considered as start again, then there is no  
            // possible solution  
            if (start == 0)  
            return -1;  
        }  
  
        // Add a petrol pump to current tour 
        curr_petrol += arr[end].petrol - arr[end].distance;  
        
  
        end = (end + 1) % n;  
    }  
  
    // Return starting point  
    return start;  
    }  
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        vector<PetrolPump> v;
        if (gas.size() == 1) {
            if (gas[0] < cost[0]) {
                return -1;
            }
        }
        for (int i =0; i < gas.size(); i++) {
            PetrolPump p = PetrolPump(gas[i],cost[i]);
            v.push_back(p);
        }
        return printTour(v,gas.size());
        
    }
};
