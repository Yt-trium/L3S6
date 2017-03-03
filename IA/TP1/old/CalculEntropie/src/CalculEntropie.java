import java.util.*;
import java.io.*;
import java.io.FileReader;

public class CalculEntropie {
	
	public static void main(String[] args) throws IOException {
        System.out.println("TP1 : calcul de l'entropie d'un texte - codage de Huffman");

        BufferedReader in
        = new BufferedReader(new FileReader("in.txt"));
        int c;
        float e;
        int size = 0;

        Vector<Integer> freqTable = new Vector<Integer>();
        
        for(c=0;c<=65533;c++)
        {
        	freqTable.add(0);
        }
        
        while((c = in.read()) != -1)
        {        	
        	freqTable.set(c, freqTable.get(c)+1);
        	size++;
        }

        e = 0;
        float pv = 0;
        
        for(c=0;c<=65533;c++)
        {
        	if(freqTable.get(c) > 0)
        	{
            	pv = (float)((float)freqTable.get(c) / (float)size);
            	e += pv * (Math.log(pv) / Math.log(2));
        	}
        }
        
        e = -e;
        
        System.out.println(e);
        
        // Créer un arbre a partir du bas
        
		
	}
}