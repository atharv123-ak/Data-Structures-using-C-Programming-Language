import java.util.Scanner;

class Stack {
    public static void main(String ar[])
    {
        int x=0,ch=0;
        Scanner sc=new Scanner(System.in);
        System.out.println("*** WELCOME TO THE STACK OPERATIONS ***");
        StackMethod sm=new StackMethod();
        while(true)
        {
            System.out.println("Enter your choice");
            System.out.println("1. Push\n", "2. Pop\n", "3. Display\n", "4. Exit\n");
            ch=sc.nextInt();
            switch(ch)
            {
                case 1:
                if(sm.isFull())
                {
                    System.out.println("Stack is OVERFLOW ");
                }
                else
                {
                    System.out.println("Enter the element to be pushed");
                    x=sc.nextInt();
                    sm.push(x);
                }
                break;
                case 2:
                if(sm.isEmpty())
                {
                    System.out.println("Stack is UNDERFLOW ");
                }
                else
                {
                    x=sm.pop();
                    System.out.println("The popped element is \n"+x);
                }
                break;
                case 3:
                if(sm.isEmpty())
                {
                    System.out.println("Stack is UNDERFLOW ");
                }
                else
                {
                    System.out.println("The elements in the stack are \n");
                    sm.display();
                }
                break;
                case 4:
                System.exit(0);
                break;
                default:
                System.out.println("Invalid choice");

            }
        }


    }
}

class StackMethod{

    int st[];
    int top;
    int size;
    StackMethod()
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the size of the stack");
        size=sc.nextInt();
        st=new int[size];
        top=-1;
        System.out.println("Stack created with size "+size);
    }
    void push()
    {
        top++;
        st[top]=x;
        System.out.println("Element pushed");

    }
    int pop()
    {
        int t;
        t=st[top];
        top--;
        return t;
    }
    void display()
    {
        for(int i=top;i>=0;i--)
        {
            System.out.println("The elements in the stack are \n");
            System.out.println(st[i]);
        }

    }
    boolean isFull()
    {
        if(top==size-1)
        {
            return true;
        }
        else
        {
            return false;
        }

    }
    boolean isEmpty()
    {
        if(top==-1)
        {
            return true;
        }
        else
        {
            return false;
        }

    }
}