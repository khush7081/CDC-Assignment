 #include<iostream>
 #include<vector>
 using namespace std;
 bool hours(vector<int>& piles,int mid,int h){
        int n=piles.size();
        long long count=0;
       
        for(int i=0;i<n;i++){
            if(mid>=piles[i]) count++;
            else if(piles[i]%mid == 0) count+=(long long)(piles[i]/mid);
            else count+=(long long )(piles[i]/mid +1);
        }
        if(count>(long long)h) return false;
        else return true;

    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int max = piles[0];
        for(int i=0;i<n;i++) if(piles[i]>max) max=piles[i];

        int low=1;   // lowest eating speed
        int high=max; // highest eating speed
        int k = -1;
        while(low<=high){
            int mid=(low+high)/2;
            if(hours(piles,mid,h)){
                k=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return k;
    }