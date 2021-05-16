// Class for matrix operations

class Matrix <T extends Number>{
	public T mat[][];
	private int matShape[];

	public Matrix(int m, int n){
		matShape = new int[2];
		matShape[0] = m;
		matShape[1] = n;
		mat = (T[][]) new Number[m][n];
	}

	public Matrix(int n){
		matShape = new int[2];
		matShape[0] = matShape[1] = n;
		mat = (T[][]) new Number[n][n];
	}

	public int[] shape(){
		return matShape;
	}

	public Matrix dot(Matrix M2){
		Matrix P = new Matrix(matShape[0], M2.shape()[1]);
		for(int i=0; i<P.shape()[0]; i++) 
			for(int j=0; j<P.shape()[1]; j++)
				for(int k=0; k<matShape[1]; k++)     
					P.mat[i][j] = (T) new Double(P.mat[i][j].doubleValue() + mat[i][k].doubleValue() * M2.mat[k][j].doubleValue());
		return P;
	}

	public T sum(){
		T total = (T) new Double(0);
		for(int i = 0; i<matShape[0]; i++)
			for(int j = 0; j<matShape[1]; j++)
				total = (T) new Double(total.doubleValue() + mat[i][j].doubleValue());
		return total;
	}

	public T[] sum(int axis){
		T total[] = (T[]) new Double[matShape[axis]];
		if(axis == 0){
			for(int i = 0; i<matShape[0]; i++)
				for(int j = 0; j<matShape[1]; j++)
					total[j] = (T) new Double(total[j].doubleValue() + mat[i][j].doubleValue());
		}
		else if(axis == 1){
			for(int i = 0; i<matShape[1]; i++)
				for(int j = 0; j<matShape[0]; j++)
					total[j] = (T) new Double(total[j].doubleValue() + mat[i][j].doubleValue());
		}
		else{
			// throw exception..
		}
		return total;
	}

	public Double mean(){
		Double val = (sum().doubleValue()/(matShape[0] * matShape[1]));
		return val;
	}

	public Double[] mean(int axis){
		T[] vals = sum(axis);
		Double meanArray[] = new Double[matShape[~axis]];
		for(int i = 0; i<(~axis); i++)
			meanArray[i] = (vals[i].doubleValue() / matShape[axis]);
		return meanArray;
	}

	public Matrix square(){
		Matrix m = new Matrix(matShape[0], matShape[1]);
		for(int i = 0; i<matShape[0]; i++)
			for(int j = 0; j<matShape[1]; j++)
				m.mat[i][j] = (T) new Double(mat[i][j].doubleValue() * mat[i][j].doubleValue());		
		return m;
	}

	public Matrix add(Matrix M){
		Matrix m = new Matrix(matShape[0], matShape[1]);
		for(int i = 0; i<matShape[0]; i++)
			for(int j = 0; j<matShape[1]; j++)
				m.mat[i][j] = (T) new Double(mat[i][j].doubleValue() + mat[i][j].doubleValue());		
		return m;		
	}

	public Matrix sub(Matrix M){
		Matrix m = new Matrix(matShape[0], matShape[1]);
		for(int i = 0; i<matShape[0]; i++)
			for(int j = 0; j<matShape[1]; j++)
				m.mat[i][j] = (T) new Double(mat[i][j].doubleValue() - mat[i][j].doubleValue());		
		return m;		
	}

	public Matrix multiply(Matrix M){
		Matrix m = new Matrix(matShape[0], matShape[1]);
		for(int i = 0; i<matShape[0]; i++)
			for(int j = 0; j<matShape[1]; j++)
				m.mat[i][j] = (T) new Double(mat[i][j].doubleValue() * mat[i][j].doubleValue());		
		return m;		
	}

	public <V extends Number> Matrix scale(V factor){
		Matrix m = new Matrix(matShape[0], matShape[1]);
		for(int i = 0; i<matShape[0]; i++)
			for(int j = 0; j<matShape[1]; j++)
				m.mat[i][j] = (T) new Double(factor.doubleValue() * mat[i][j].doubleValue());		
		return m;		
	}
}


public class testMatrix{
	public static void main(String args[]){
		Matrix a = new Matrix(3, 4);
		Matrix b = new Matrix(3, 4);
		for(int i=0; i<3; i++)
			for(int j=0; j<4; j++){
				a.mat[i][j] = (i + j);
				b.mat[i][j] = (i - j);	
			}
		Matrix <?> c = a.add(b);
		for(int i=0; i<3; i++){
			for(int j=0; j<4; j++){
				System.out.print(c.mat[i][j] + " ");
			}
			System.out.print("\n");
		}
	}
}