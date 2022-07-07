// https://www.interviewbit.com/problems/evaluate-expression/

bool isOperand(string s){
    return s=="+"||s=="-"||s=="*"||s=="/";
}

int Solution::evalRPN(vector<string> &A) {
    
    stack<int>s;
    
    for(int i=0;i<A.size();i++){
        
        if(isOperand(A[i])){
            
            int oprnd2=s.top();
            s.pop();
            int oprnd1=s.top();
            s.pop();
            
            int val;
            if(A[i]=="+")val=oprnd1+oprnd2;
            else if(A[i]=="-")val=oprnd1-oprnd2;
            else if(A[i]=="*")val=oprnd1*oprnd2;
            else if(A[i]=="/")val=oprnd1/oprnd2;
            s.push(val);
        }else s.push(stoi(A[i]));
        
    }
    
    return s.top();
}


//Reverse Polish -> PostFix

// b*b-4*a*c
//=>(bb)*-4*(a*c)
//=>(bb)*-4*(ac)*
//=>(bb)*-(4(ac)*)*
//=>bb*4ac**-