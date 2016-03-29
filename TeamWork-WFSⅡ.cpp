import java.util.*;
import java.util.Map.Entry;
import java.io.*;

public class WordCount3
{
	public static void main(String[] args)  throws Exception  
	{ 
		Map<String,Integer> map=new HashMap<String,Integer>();
		System.out.println("请输入所要查询的文件路径及文件名：");
		Scanner bs=new Scanner (System.in);
		String files=bs.nextLine();
		           
		File file = new File(files+".txt");
        FileReader reader = new FileReader(file);
        int fileLen = (int)file.length();
        char[] chars = new char[fileLen];
        reader.read(chars);
        String text = String.valueOf(chars);

		text = text.replaceAll("[\\‘‘.“”，,]", "");  //删除字符串中的标点符号
		text = text.toLowerCase();//将文字全部转换为小写
		StringTokenizer take =  new StringTokenizer(text); //StringTokenizer是一个用来分隔String的应用类
		String word = new String();
		int i =0;
		while( take.hasMoreElements() )
		{
			
			word=take.nextToken() ;
			if(word.length()>=4)
			{ 
				Integer count = map.get(word);
				if(count == null)
				{
					map.put(word,1);
				}
				else{
				map.put(word,++count);
				}
			}
			i++;
		}
		
		//排序
		List<Map.Entry<String, Integer>> list = new ArrayList<Map.Entry<String, Integer>>(map.entrySet());
		Collections.sort( list, new Comparator<Map.Entry<String, Integer>>()
		{     
			public int compare(Map.Entry<String, Integer> o1, Map.Entry<String, Integer> o2) 
			{     
				if(o1.getValue()<o2.getValue())
				  return 1;
				else if(o1.getValue()>o2.getValue())
				  return -1;
				else
				  return(o1.getKey().compareTo(o2.getKey()));
			}
		} );
		   
		   System.out.println("请输入要查询的单词：");
           Scanner sc=new Scanner(System.in);
           String scword=sc.nextLine().toLowerCase();
           for(Map.Entry<String,Integer> entry : map.entrySet())
           {
           	   if(entry.getKey().equalsIgnoreCase(scword)) 
           	   {
           	   	System.out.println(scword+"在该文本中出现"+ entry.getValue()+"次\r\n已保存入指定目录文本中");
           	   	File outfile = new File("D:\\Software\\SorfwareTest\\Result2.txt"); 
           	   	try  
           	   	{ 
           	   		if (file.exists()) outfile.delete(); 
           	   		BufferedWriter bw = new BufferedWriter(new FileWriter(outfile)); 
           	   		StringBuffer out = new StringBuffer(); 
           	   		 out.append(scword+"在该文本中出现"+ entry.getValue()+"次\r\n");  
           	   		 bw.write(out.toString()); 
           	   		 bw.flush(); 
           	   		 bw.close(); 
           	   		 }  
           	   		 catch (IOException e) 
           	   		 { 
           	   		 	 e.printStackTrace(); 
           	   		 }
           	   		}
			   else  continue;
		   }
		   
		  
		
		//输出TXT
		

   }
  
  }


