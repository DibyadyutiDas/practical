public class StringandStringBuffer {
    public static void main(String[] args) {
        StringBuffer sb = new StringBuffer("Hello");
        sb.setCharAt(0, 'h');
        sb.setLength(4);
        sb.append(" World");
        sb.insert(6, "Java ");
        String s1 = sb.toString();
        String s2 = "h World";
        System.out.println("StringBuffer: " + sb);
        System.out.println("Equals: " + s1.equals(s2));
    }
}