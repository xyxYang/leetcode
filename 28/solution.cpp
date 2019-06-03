class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0){
            return 0;
        }
        int i;
        # 生成next数组
        vector<int> next;
        next.push_back(-1);//next数组初值为-1 
        int j=0,k=-1; 
        while(j<needle.size()) { 
            if(k==-1||needle[j]==needle[k])//str[j]后缀 str[k]前缀 
            { 
                j++; k++; next.push_back(k); 
            } 
            else { 
                k=next[k]; 
            } 
        }

        
        # 使用kmp算法进行计算
        
        i = j = 0;
        while(i < haystack.size() && j < needle.size()){
            if(haystack[i] == needle[j]){
                i++;
                j++;
            }else{
                if(j == 0){
                    i++;
                }else{
                    j = next[j];
                }
            }
        }
        if(j == needle.size()){
            return i-j;
        }
        return -1;
    }
};
