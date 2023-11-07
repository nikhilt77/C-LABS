import java.util.*;
class Garbage{
public void finalize(){
System.out.println("Garbage collected");
}
}
class GarbageCollector{
  public static void main(String args[]){
  long mem1,mem2,mem3;
  Garbage garbage=new Garbage();
  Runtime r=Runtime.getRuntime();
  System.out.println("Total memory:"+r.totalMemory());
  garbage=null;
  int var[]=new int[10];
  mem2=r.freeMemory();
  System.out.println("Free memory:"+mem2);
  r.gc();
  mem3=r.freeMemory();
  System.out.println("Free memory after garbage collection:"+mem3);
}
}

  

  
