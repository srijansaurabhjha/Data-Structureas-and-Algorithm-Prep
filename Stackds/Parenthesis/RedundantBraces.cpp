// https://www.interviewbit.com/problems/redundant-braces/

bool isOperator(char ch){
    return ch=='+'||ch=='-'||ch=='*'||ch=='/';
}

int Solution::braces(string A) {
    
    stack<int>s;
    
    for(auto& ch:A){
        
        if(ch=='('||isOperator(ch)){
            s.push(ch);
        }else{
            
//           For ) or lower case letter
            
              if(ch==')'){
                  //->check if there exists any operator b/w opening and closing bracket
                  //is there is no operator then the brackets are redundant
                  
                  bool isRedundant=true;
                  
                  while(!s.empty()&&s.top()!='('){
                      
                      if(isOperator(s.top())){
                          isRedundant=false;
                      }
                      
                      s.pop();
                  }
                  
                  if(isRedundant)return 1;
                  
                  //Pop the opening bracket also
                  s.pop();
              }
            
        }
        
    }
    //No redundant brackets found
    return 0;
}

