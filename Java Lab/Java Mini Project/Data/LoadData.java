package Data;

import java.util.*;
import java.io.*;

public class LoadData {
	
	public double[][] xValues;
	public double[] yValues;
	public double[] mean = new double[6];
	public double[] sd = new double[6];

	// Loads data from the file into the arrays
	public void loadData(String fileLocation) {
		// Size of the data set is known
		xValues = new double[400][7];
		yValues = new double[400];

		int row;
		String inputRow = "";

		try {
			
			Scanner read = new Scanner(new BufferedReader(new FileReader(fileLocation)));
			int i,j;

			// The first row is just the headings of the coloumns, so it is just ignored
			inputRow = read.nextLine();

			for(row = 0; read.hasNextLine() ; row++) {

				// Read a row of the .csv (comma separated values) into a string
				inputRow = read.nextLine();

				// Split the string with the seperator as comma
				String[] input = inputRow.split(",");

				// Parse each value in the string array into double and store it in the features array
				// First value is the serial number, so it is skipped
				for(i=0; i<input.length-2 ; i++)
					xValues[row][i] = Double.parseDouble(input[i+1]);

				// Last value in the value is the probability of the admission of i'th training example
				yValues[row] = Double.parseDouble(input[input.length-1]);
			}
		}

		// In case any unknown exception occurs
		catch(Exception e) { System.out.println(e); }
	}

	// Display the data upto n rows
	public void displayData(int n) {
		int i,j;

		for(i=0;i<n;i++) {
			for(j=0;j<7;j++)
				System.out.print(xValues[i][j] + " ");

			System.out.println("   " + yValues[i]);
		}
	}

	// Normalizing the data (Changing them to be a value between 0 and 1)
	public void normalizeData() {

		int i,j;

		// Calculating both mean each training example
		// Iterating through all features
		for(j=0;j<6;j++) {
			for(i=0;i<400;i++)
				mean[j] += xValues[i][j];

			mean[j] /= 400;
		}

		// Calculating Standard deviation of each feature
		for(j=0;j<6;j++) {
			for(i=0;i<400;i++)
				sd[j] += (xValues[i][j] - mean[j]) * (xValues[i][j] - mean[j]);

			sd[j] /= 400;
			sd[j] = java.lang.Math.sqrt(sd[j]);
		}


		// Normalizing each value
		for(i=0;i<400;i++)
			for(j=0;j<6;j++)
				xValues[i][j] = (xValues[i][j] - mean[j])/sd[j];
	}
}

