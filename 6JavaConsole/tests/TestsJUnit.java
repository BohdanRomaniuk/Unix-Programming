package tests;

import static org.junit.jupiter.api.Assertions.*;

import java.io.File;
import java.io.IOException;
import java.util.concurrent.TimeUnit;

import org.junit.jupiter.api.Test;

import program.OldestFolderSearcher;
import program.RepeatingFilesRemover;

class TestsJUnit 
{
	private static void RemoveDirs(File root)
	{
		for(File dir : root.listFiles())
		{
			if(dir.isDirectory())
			{
				RemoveDirs(dir);
			}
			dir.delete();
		}
	}
	
	private static void CreateEmptyFile(String path)
	{
		try 
		{
			File file = new File(path);
			file.createNewFile();
		} 
		catch (IOException e) 
		{
			e.printStackTrace();
		}
	}
	
	private static void Sleep(int seconds)
	{
		try 
		{
			TimeUnit.SECONDS.sleep(seconds);
		} 
		catch (InterruptedException e) 
		{
			e.printStackTrace();
		}
	}

	@Test
	void Test1_1()
	{
		File root = new File("./tests/");
		root.mkdirs();
		new File("./tests/1").mkdirs();
		Sleep(1);
		new File("./tests/2").mkdirs();
		Sleep(1);
		new File("./tests/3").mkdirs();
		
		OldestFolderSearcher searcher = new OldestFolderSearcher();
		String result = searcher.FindOldestDir(root.getAbsolutePath());
		
		RemoveDirs(root);
		root.delete();
		assertTrue(result.contains("/1"));
	}

	@Test
	void Test1_2()
	{
		File root = new File("./tests/");
		root.mkdirs();
		new File("./tests/1").mkdirs();
		Sleep(1);
		new File("./tests/1/2").mkdirs();
		Sleep(1);
		new File("./tests/3").mkdirs();
		
		OldestFolderSearcher searcher = new OldestFolderSearcher();
		String result = searcher.FindOldestDir(root.getAbsolutePath());
		
		RemoveDirs(root);
		root.delete();
		assertTrue(result.contains("/1"));
	}
	
	@Test
	void Test1_3()
	{
		File root = new File("./tests/");
		root.mkdirs();
		new File("./tests/3").mkdirs();
		Sleep(1);
		new File("./tests/3/2").mkdirs();
		Sleep(1);
		new File("./tests/4").mkdirs();
		Sleep(1);
		new File("./tests/1").mkdirs();
		Sleep(1);
		new File("./tests/3/5").mkdirs();
		
		OldestFolderSearcher searcher = new OldestFolderSearcher();
		String result = searcher.FindOldestDir(root.getAbsolutePath());
		
		RemoveDirs(root);
		root.delete();
		assertTrue(result.contains("/3/2"));
	}
	
	@Test
	void Test2_1()
	{
		File root = new File("./tests/");
		root.mkdirs();
		CreateEmptyFile("./tests/modest.h");
		CreateEmptyFile("./tests/modest.cpp");
		CreateEmptyFile("./tests/modest.txt");
		
		RepeatingFilesRemover remover = new RepeatingFilesRemover();
		int result = remover.RemoveRepeatingFiles(root.getAbsolutePath(), ".cpp");
		boolean firstRemoved = !RepeatingFilesRemover.FileExist("./tests/modest.h");
		boolean thirdRemoved = !RepeatingFilesRemover.FileExist("./tests/modest.txt");
		
		RemoveDirs(root);
		root.delete();
		assertTrue(result == 2 && firstRemoved && thirdRemoved);
	}
	
	@Test
	void Test2_2()
	{
		File root = new File("./tests/");
		root.mkdirs();
		CreateEmptyFile("./tests/modest.h");
		CreateEmptyFile("./tests/modest.cpp");
		CreateEmptyFile("./tests/modest.txt");
		CreateEmptyFile("./tests/roman.h");
		CreateEmptyFile("./tests/roman.cpp");
		
		RepeatingFilesRemover remover = new RepeatingFilesRemover();
		int result = remover.RemoveRepeatingFiles(root.getAbsolutePath(), ".cpp");
		boolean firstRemoved = !RepeatingFilesRemover.FileExist("./tests/modest.h");
		boolean thirdRemoved = !RepeatingFilesRemover.FileExist("./tests/modest.txt");
		boolean fourthRemoved = !RepeatingFilesRemover.FileExist("./tests/roman.h");
		
		RemoveDirs(root);
		root.delete();
		assertTrue(result == 3 && firstRemoved && thirdRemoved && fourthRemoved);
	}
	
	@Test
	void Test2_3()
	{
		File root = new File("./tests/");
		root.mkdirs();
		CreateEmptyFile("./tests/modest.h");
		CreateEmptyFile("./tests/modest.cpp");
		CreateEmptyFile("./tests/modest.txt");
		CreateEmptyFile("./tests/roman.h");
		CreateEmptyFile("./tests/roman.cpp");
		CreateEmptyFile("./tests/romn.cpp");
		CreateEmptyFile("./tests/buchik.cpp");
		CreateEmptyFile("./tests/buchk.cpp");
		
		RepeatingFilesRemover remover = new RepeatingFilesRemover();
		int result = remover.RemoveRepeatingFiles(root.getAbsolutePath(), ".cpp");
		boolean firstRemoved = !RepeatingFilesRemover.FileExist("./tests/modest.h");
		boolean thirdRemoved = !RepeatingFilesRemover.FileExist("./tests/modest.txt");
		boolean fourthRemoved = !RepeatingFilesRemover.FileExist("./tests/roman.h");
		
		RemoveDirs(root);
		root.delete();
		assertTrue(result == 3 && firstRemoved && thirdRemoved && fourthRemoved);
	}
}
