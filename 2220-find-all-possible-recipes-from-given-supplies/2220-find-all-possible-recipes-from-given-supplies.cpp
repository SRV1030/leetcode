class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string>st(supplies.begin(),supplies.end());
        vector<string> ans;
        int fr=0;
        while(fr<recipes.size()){
            int nf=0;
            for(int i=0;i<recipes.size();++i){
                if(recipes[i]!="$"){
                    int nfing=1;
                   for(auto&ing:ingredients[i]){
                        if(!st.count(ing)){
                            nfing=0;
                            break;
                        }
                   }
                    if(nfing){
                        nf=1;
                        fr++;
                        st.insert(recipes[i]);
                        ans.push_back(recipes[i]);
                        recipes[i]="$";
                    }
                }
            }
            if(!nf) break;
        }
        return ans;
    }
};