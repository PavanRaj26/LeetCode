#include <stdio.h>

//Preorder
//Inorder
class PetrolPump {
    int petrol;
    int distance;
    
};
void firstCircularTour(PetrolPum arr[]) {
    int petrol=arr[0].petrol-arr[0].distance;
    int start = 0;
    int end = 1;
    while (end != start || petrol < 0) {
        while (petrol < 0 && end != start) {
            petrol -= arr[start].petrol - arr[start].distance;
            start = (start + 1) % n;
            if (start == 0) return -1;
        }
        petrol += arr[end].petrol - arr[end].distance;
        end = (end + 1) % n;
    }
    return start;
    
}
int main() {
	//code
	
	return 0;
}