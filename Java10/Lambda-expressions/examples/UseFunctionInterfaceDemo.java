// Use the Function built-in functional interface.
// Import the Function interface.

import java.util.function.Function;
class UseFunctionInterfaceDemo {
    public static void main(String args[])
    {
        Function<Integer, String> obj = (n) -> {     
            return "str@"  + n.toString();
        };
        System.out.println(obj.apply(3));
        System.out.println(obj.apply(5));
    }
}

