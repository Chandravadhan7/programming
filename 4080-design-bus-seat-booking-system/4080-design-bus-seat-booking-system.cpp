class BusBooking {
public:
    vector<vector<int>> seats;
    int total = 0;
    int booked = 0;
    BusBooking(int n) {
        vector<vector<int>> busseats(n+1,vector<int>(4,0));
        seats = busseats;
    }
    
    void toggle(string seat) {
        int l = seat.length();
        int col = seat[0] - 'A';
        int row = stoi(seat.substr(1,l-1));

        if(seats[row][col] != 0){
            total -= seats[row][col];
            seats[row][col] = 0;
            booked--;
        }else{
            if(col == 0 && seats[row][col+1] != 0){
                total += 3;
                seats[row][col] = 3;
            }else if(col == 3 && seats[row][col-1] != 0){
                total += 3;
                seats[row][col] = 3;
            }else{
                total++;
                seats[row][col] = 1;
            }
            booked++;
        }
    }
    
    int getTotalTime() {
        return total;
    }
    
    int getMinTime() {
        return booked;
    }
};

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */