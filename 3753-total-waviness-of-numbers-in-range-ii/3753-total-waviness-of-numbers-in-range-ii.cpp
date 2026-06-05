class Solution {
public:
    typedef long long ll;
    string s;
    int n;
    ll dpTotalNumber[16][10][10];
    ll dpTotalWaviness[16][10][10];

    pair<ll,ll> solve(int curr, int prev_prev, int prev, bool isLimitedWithActualNumber,bool isLeadingZero)
    {
        if(curr==n)
        {
            //then no more score can be generated and we found last number
            return {1,0};
        }

        if(!isLimitedWithActualNumber && !isLeadingZero && prev_prev>=0 && prev>=0)
        {
            if(dpTotalNumber[curr][prev_prev][prev]!=-1 && dpTotalWaviness[curr][prev_prev][prev]!=-1)
            {
                return {dpTotalNumber[curr][prev_prev][prev],dpTotalWaviness[curr][prev_prev][prev]};
            }
        }

        ll total_numbers=0;
        ll total_wave_score=0;

        ll limit_digit=(isLimitedWithActualNumber)?s[curr]-'0':9;

        for(int digit=0;digit<=limit_digit;digit++)
        {
            bool isnewLeadingZero=(isLeadingZero && (digit==0));
            int new_prev_prev=prev;
            int new_prev=isnewLeadingZero?-1:digit;
            bool newisLimitedWithActualNumber=(isLimitedWithActualNumber && (digit==limit_digit));

            auto [remainTotalNumbers,remainTotalWaveScore]=solve(curr+1,new_prev_prev,new_prev,newisLimitedWithActualNumber,isnewLeadingZero);

            if(!isnewLeadingZero && prev_prev>=0 && prev>=0)
            {
                bool isPeak=(prev_prev<prev && prev>digit);
                bool isValley=(prev_prev>prev && prev<digit);

                if(isPeak || isValley)
                {
                    total_wave_score+=remainTotalNumbers;
                }

                
            }
            total_numbers+=remainTotalNumbers;
            total_wave_score+=remainTotalWaveScore;
        }

        if(!isLimitedWithActualNumber && !isLeadingZero && prev_prev>=0 && prev>=0)
        {
            dpTotalNumber[curr][prev_prev][prev]=total_numbers;
            dpTotalWaviness[curr][prev_prev][prev]=total_wave_score;
        }
        return {total_numbers,total_wave_score};

    }

    ll func(ll num)
    {
        if(num<100) return 0;
        s=to_string(num);
        n=s.size();
        memset(dpTotalNumber,-1,sizeof(dpTotalNumber));
        memset(dpTotalWaviness,-1,sizeof(dpTotalWaviness));
        auto [total_numbers,total_waviness_score]=solve(0,-1,-1,true,true);
        return total_waviness_score;
    }
    long long totalWaviness(long long num1, long long num2) {
        return (func(num2)-func(num1-1));
    }
};