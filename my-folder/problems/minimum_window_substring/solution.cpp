class Solution {
public:
    string minWindow(string s, string t) {
        
        if (s.size()<t.size() || s.size()==0 || t.size()==0){
            return "";
        }
        
        map<char,int> mapS;
        map<char,int> mapT;
        map<char,int>::iterator itr;
        map<char,int>::iterator itr2;
        
        for (int i=0;i<t.size();i++){
            if (mapT.find(t[i])!=mapT.end()){
                itr = mapT.find(t[i]);
                itr->second++;
            }
            else{
                mapT.insert(pair<int,int>(t[i],1));
            }
        }
        
        cout << mapT.size() << endl;
        /*
        for (int i=0;i<s.size();i++){
            if (mapS.find(s[i])!=mapS.end()){
                itr = mapS.find(s[i]);
                itr->second++;
            }
            else{
                mapS.insert(pair<int,int>(s[i],1));
            }
        }*/
        
        int left, right;
        left = right = 0;
        
        int req = mapT.size();
        int formed = 0;
        string ans = "";
        
        while(right<s.size()){
            itr = mapS.find(s[right]);
            
            if (itr!=mapS.end()){
                itr->second++;
                // cout << itr->first << " " << itr->second << endl;
            }
            else{
                mapS.insert(pair<char,int>(s[right],1));
            }
            
            itr2 = mapT.find(s[right]);
            
            itr = mapS.find(s[right]);
            // cout << itr->first << " " << itr2->first << " " << itr->second << " " << itr2->second << endl;
            if (itr2!=mapT.end() && itr2->second==itr->second){
                formed++;
                // cout << formed << endl;
            }
            
            // cout << formed << " " << req << " " << right << endl;
            
            while(left<=right && formed==req){
                string temp = s.substr(left, right-left+1);
                // cout << temp << endl;
                ans = ans.size()==0 || temp.size()< ans.size() ? temp : ans;
                
                itr = mapS.find(s[left]);
                itr->second--;
                
                itr2 = mapT.find(s[left]);
                
                if (itr2!=mapT.end() && itr2->second > itr->second)
                    formed--;
                
                left++;
            }
            
            right++;
        }
        
        return ans;
    }
};