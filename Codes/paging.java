public class paging {
    
    public static void main(String[] args) {
        //single level paging
        //maximum page table entry size possible such that the 
        //entire page table fits well




        

        int v=32;        
        int page=4;
        int phy=32;
        int controlBits=2;

        //kb=10, mb=20, gb=30, tb=40;
        int virtAddBits=(int)(Math.log(v)/Math.log(2))+40;
        virtAddBits=32;
        int pageBits=(int)(Math.log(page)/Math.log(2))+10;
        int phyBits=(int)(Math.log(phy)/Math.log(2))+10;
        int pages=virtAddBits-pageBits;
        int pageFrames=phyBits-pageBits;
        int pageTableEntrySize_B=pageFrames+pages+controlBits;
        System.out.println(pageTableEntrySize_B);

        System.out.println((int)Math.pow(2,pageTableEntrySize_B)+"bytes");
        //System.out.println(pages+" "+pageBits);

    }
    
}
