class MyQueue {
public:
    stack<int> input, output;

    MyQueue() 
    {
        
    }
    
    void push(int x) 
    {
        input.push(x); // Push directly
    }
    
    int pop() 
    {
        if(output.empty()) 
        {
            // shifts all elements from input to output
            while(!input.empty()) 
            {
                output.push(input.top());
                input.pop();
            }
        }

        int val = output.top();
        output.pop(); // front element removed
        return val;
    }
    
    int peek() 
    {
        if(output.empty()) 
        {
            while(!input.empty()) 
            {
                output.push(input.top());
                input.pop();
            }
        }

        return output.top(); // front element
    }
    
    bool empty() 
    {
        return input.empty() && output.empty();
    }
};