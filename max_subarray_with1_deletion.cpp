int n=arr.size();
        int curr_sum=0;
        int max_sum=INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            curr_sum+=arr[i];
            
            max_sum=max(max_sum,curr_sum);
            
            if(curr_sum<0)
            {
                curr_sum=0;
            }
        }
        
        if(max_sum<0)
        return max_sum;
        
        int forward[n],backward[n];
        
        
        memset(forward,0,sizeof(forward));
        memset(backward,0,sizeof(backward));
        
        if(arr[0]>0)
        forward[0]=arr[0];
        
        for(int i=1;i<n;i++)
        {
            if(arr[i]+forward[i-1]>=0)
            {
                forward[i]=arr[i]+forward[i-1];
            }
            else
            {
                forward[i]=0;
            }
        }
        
        if(arr[n-1]>0)
        backward[n-1]=arr[n-1];
        
        for(int i=n-2;i>=0;i--)
        {
            if(arr[i]+backward[i+1]>=0)
            {
                backward[i]=arr[i]+backward[i+1];
            }
            else
            {
                backward[i]=0;
            }
        }
        

        
        for(int i=1;i<n-1;i++)
        {
            max_sum=max(max_sum,forward[i-1]+backward[i+1]);
        }
        
        return max_sum;
    }
