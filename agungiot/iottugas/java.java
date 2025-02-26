public class CetakArray {
    public static void main(String[] args) {
       
        int[] angkaArray;
        
        angkaArray = new int[]{10, 20, 30, 40, 50};

        System.out.println("Angka dalam array:");
        for (int i = 0; i < angkaArray.length; i++) {
            System.out.println(angkaArray[i]);
        }
    }
}