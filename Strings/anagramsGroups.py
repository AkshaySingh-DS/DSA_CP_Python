"""
Problem Statement : 
Time Complexity :
"""
#check anagram O(N) -> N size of string
def isAnagram(str1, str2):
    count1 = [0] * 256
    count2 = [0] * 256

    lstr1, lstr2 = len(str1), len(str2)
    if lstr1 != lstr2:
        return False

    # logic
    for i in range(lstr1):
        count1[ord(str1[i])] += 1
        count2[ord(str2[i])] += 1

    # check anagram 
    for i in range(256):
        if count1[i] != count2[i]:
            return  False

    return True

# O(N^2) * O(m) -> N is the total words, m is the size of words(string)
def groupAnagrams(words, n):
    l = len(words)
    visited = [False] * l
    groups = []
    for i in range(l):
        group = []
        if visited[i] == False:
            group.append(words[i])
            for j in range(i+1, l):
                if visited[j] == False:
                    result = isAnagram(words[i], words[j])
                    if result:
                        visited[j] = True
                        group.append(words[j])

            visited[i] = True
            groups.append(group)

    return groups

#using hashmap -> O(N) * m log(m), space is O(N)
def storeAnagrams(wordslist):
    hashmap = dict()
    for w in wordslist:
        temp = ''.join(sorted(w))
        if hashmap.get(temp) == None:
            hashmap[temp] = [w]
        else:
            hashmap[temp].append(w)

    #printAnagrams(hashmap)
    return [v for _, v in hashmap.items()]

"""
CPP SOLUTION:
//APPROACH-1 O(N^2 * S)
//where S is the length of string, N is the number of strings in vactor. 
class Solution{
  private:
    bool isAnagram(string str1, string str2){
        
        int countArr1 [26] = {0};
        int countArr2 [26] = {0};
        
        if (str1.length() != str2.length())
            return false;
        
        for(int i = 0; i < str1.length(); i++){
            
            countArr1[str1[i] - 'a']++;
            countArr2[str2[i] - 'a']++;
        }
        
        for (int  i = 0; i < 26; i++){
            
            if (countArr1[i] != countArr2[i])
                return false;
        }
        
        return true;
    }
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        int n = string_list.size(); 
        vector <bool> visited(n, false);
        vector <vector<string>> ans; 
        
        //find all grouo of anagrams
        for(int i = 0; i < n; i++){
            
            //make all group related to this
            if(!visited[i]){
                //find all grouo of anagrams
                vector <string> gp;
                gp.push_back(string_list[i]);
                for(int j = i + 1; j < n ; j++){
                    
                    // j is also not visited
                    if(!visited[j]){
                        
                        if (isAnagram(string_list[i], string_list[j])){
                            
                            gp.push_back(string_list[j]);
                            //also visite it
                            visited[j] = true;
                        }
                    }
                }
                
                visited[i] = true;
                ans.push_back(gp);
            }
        }
        return ans;
    }
};

//APPROACH-2 (More Optimized using hash and sorting), 
//TIME COMPLEXITY : O(N) * m log(m), space is O(N) , where m is the size of string and N is the number of strings in given vector

 vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        vector <vector<string>> ans; 
        unordered_map <string, vector<string>> map;
        
        //optimized approach using hashmapm and Sorting 
        for(auto str : string_list){
            
            //key not found in map
            string temp = str;
            sort(temp.begin(), temp.end());
            //if(map.find(temp) == map.end()){
                //vector <string> v;
                //v.push_back(str);
                //map[temp] = v;
            //}
            //when key found
            //else { 
            
            //even if key not exists it create a new key and append the value diff from python
            //python through an error 

            map[temp].push_back(str);

            
            //}
   
        }
        //get the all groups made in above process
        
        for(auto x : map){
            
            ans.push_back(x.second);
        }
        
        return ans;
        
}

"""


if __name__ == "__main__":
    n = int(input())
    words = [word for word in input().split()]
    print(storeAnagrams(words))
    """anagram_groups = groupAnagrams(words, n)
    for gp in anagram_groups:
        for anagram in gp:
            print(f"{anagram}", end=" ")
        print()
    """

