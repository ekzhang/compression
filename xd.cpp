#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> ii;

#define error(x) err(#x, x)
template <class T> void err(string s, T x) { cerr << s << " = " << x << endl; }

const int N = 256;
int R[N][N], G[N][N], B[N][N];
int R2[N][N], G2[N][N], B2[N][N];
double R3[N][N], G3[N][N], B3[N][N];
double c[N][N];
int b;
int A[20013];

double p(double x, double y) {
	return sqrt(x * x + y * y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int firstnum;
	cin >> firstnum;

	if (firstnum == -1) {
		// encoding
		cin >> b;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> R[i][j] >> G[i][j] >> B[i][j];
			}
		}

		if (b == 20000) {
			for (int i =i = 0; i < N; i += 2) {
				for (int j = 0; j < N; j += 2) {
					R2[i][j] = (R[i][j] + R[i+1][j] + R[i][j+1] + R[i+1][j+1] + 2) / 4;
					G2[i][j] = (G[i][j] + G[i+1][j] + G[i][j+1] + G[i+1][j+1] + 2) / 4;
					B2[i][j] = (B[i][j] + B[i+1][j] + B[i][j+1] + B[i+1][j+1] + 2) / 4;
					// R2[i][j] = R[i][j];
					// G2[i][j] = G[i][j];
					// B2[i][j] = B[i][j];

				}
			}

			for(int i = 0; i < N; i += 2){
				for(int j = 0; j < N; j += 2){
					R2[i][j] = R2[i][j] >> 5;
					G2[i][j] = G2[i][j] >> 5;
					B2[i][j] = B2[i][j] >> 6;
				}
			}
			for(int i = 0; i < N; i += 2){
				for(int j = 0; j < N; j += 2){
					A[i*N/4 + j/2] = (R2[i][j] << 5) + (G2[i][j] << 2) + B2[i][j];
				}
			}
			cout << b << endl;
			for(int i = 0; i < b; i++) {
				cout << A[i] << '\n';
			}
		}

		if (b == 2000) {
			for (int i = 0; i < N; i += 6) {
				for (int j = 0; j < N; j += 6) {
					// R2[i][j] = (R[i][j] + R[i+1][j] + R[i][j+1] + R[i+1][j+1] + 2) / 4;
					// G2[i][j] = (G[i][j] + G[i+1][j] + G[i][j+1] + G[i+1][j+1] + 2) / 4;
					// B2[i][j] = (B[i][j] + B[i+1][j] + B[i][j+1] + B[i+1][j+1] + 2) / 4;
					R2[i][j] = R[i][j];
					G2[i][j] = G[i][j];
					B2[i][j] = B[i][j];

				}
			}

			for(int i = 0; i < N; i += 6){
				for(int j = 0; j < N; j += 6){
					R2[i][j] = R2[i][j] >> 5;
					G2[i][j] = G2[i][j] >> 5;
					B2[i][j] = B2[i][j] >> 6;
				}
			}
			for(int i = 0; i < N; i += 6){
				for(int j = 0; j < N; j += 6){
					A[i*N/36 + j/6] = (R2[i][j] << 5) + (G2[i][j] << 2) + B2[i][j];
				}
			}
			cout << b << endl;
			for(int i = 0; i < b; i++) {
				cout << A[i] << '\n';
			}
		}

		if (b == 200){
			for (int i = 0; i < N; i += 19) {
				for (int j = 0; j < N; j += 19) {
					// R2[i][j] = (R[i][j] + R[i+1][j] + R[i][j+1] + R[i+1][j+1] + 2) / 4;
					// G2[i][j] = (G[i][j] + G[i+1][j] + G[i][j+1] + G[i+1][j+1] + 2) / 4;
					// B2[i][j] = (B[i][j] + B[i+1][j] + B[i][j+1] + B[i+1][j+1] + 2) / 4;
					R2[i][j] = R[i][j];
					G2[i][j] = G[i][j];
					B2[i][j] = B[i][j];

				}
			}

			for(int i = 0; i < N; i += 19){
				for(int j = 0; j < N; j += 19){
					R2[i][j] = R2[i][j] >> 5;
					G2[i][j] = G2[i][j] >> 5;
					B2[i][j] = B2[i][j] >> 6;
				}
			}
			for(int i = 0; i < N; i += 19){
				for(int j = 0; j < N; j += 19){
					A[i*N/361 + j/19] = (R2[i][j] << 5) + (G2[i][j] << 2) + B2[i][j];
				}
			}
			cout << b << endl;
			for(int i = 0; i < b; i++) {
				cout << A[i] << '\n';
			}
		}
	}
	else {
		// decoding
		b = firstnum;

		for (int i = 0; i < b; i++) {
			cin >> A[i];
		}

		if (b == 20000){
			for (int i = 0; i < N; i += 2) {
				for (int j = 0; j < N; j += 2) {
					int px = A[i*N/4 + j/2];
					int r = ((px & 0b11100000) >> 5 << 5) + 16;
					int g = ((px & 0b00011100) >> 2 << 5) + 16;
					int b = ((px & 0b00000011) >> 0 << 6) + 32;
					for (int di = i-1; di <= i+1; di++) {
						for (int dj = j-1; dj <= j+1; dj++) {
							R[(di + N) % N][(dj + N) % N] += r;
							G[(di + N) % N][(dj + N) % N] += g;
							B[(di + N) % N][(dj + N) % N] += b;
						}
					}
				}
			}

			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					int amt = (i % 2) + (j % 2);
					R[i][j] /= (1<<amt);
					G[i][j] /= (1<<amt);
					B[i][j] /= (1<<amt);
				}
			}

			cout << -1 << '\n' << 0 << '\n';
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					cout << R[i][j] << '\n' << G[i][j] << '\n' << B[i][j] << '\n';
				}
			}
		}

		if (b == 2000){
			for (int i = 0; i < N; i += 6) {
				for (int j = 0; j < N; j += 6) {
					int px = A[i*N/36 + j/6];
					int r = ((px & 0b11100000) >> 5 << 5) + 16;
					int g = ((px & 0b00011100) >> 2 << 5) + 16;
					int b = ((px & 0b00000011) >> 0 << 6) + 32;

					R[i][j] = r;
					G[i][j] = g;
					B[i][j] = b;

					for (int di = i-5; di <= i+5; di++) {
						for (int dj = j-5; dj <= j+5; dj++) {
							if (di == i && dj == j) continue;
							double weight = 1 / p(di - i, dj - j);
							c[di][dj] += weight;
							R[(di + N) % N][(dj + N) % N] += r * weight;
							G[(di + N) % N][(dj + N) % N] += g * weight;
							B[(di + N) % N][(dj + N) % N] += b * weight;
						}
					}
				}
			}

			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (i % 6 == 0 && j % 6 == 0) continue;
					R[i][j] /= c[i][j];
					G[i][j] /= c[i][j];
					B[i][j] /= c[i][j];
				}
			}

			cout << -1 << '\n' << 0 << '\n';
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					cout << R[i][j] << '\n' << G[i][j] << '\n' << B[i][j] << '\n';
				}
			}
		}
		if (b == 200){
			for (int i = 0; i < N; i += 19) {
				for (int j = 0; j < N; j += 19) {
					int px = A[i*N/361 + j/19];
					int r = ((px & 0b11100000) >> 5 << 5) + 16;
					int g = ((px & 0b00011100) >> 2 << 5) + 16;
					int b = ((px & 0b00000011) >> 0 << 6) + 32;

					R[i][j] = r;
					G[i][j] = g;
					B[i][j] = b;

					for (int di = i-18; di <= i+18; di++) {
						for (int dj = j-18; dj <= j+18; dj++) {
							if (di == i && dj == j) continue;
							double weight = 1 / p(di - i, dj - j);
							c[di][dj] += weight;
							R[(di + N) % N][(dj + N) % N] += r * weight;
							G[(di + N) % N][(dj + N) % N] += g * weight;
							B[(di + N) % N][(dj + N) % N] += b * weight;
						}
					}
				}
			}

			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (i % 19 == 0 && j % 19 == 0) continue;
					// c[i][j] = .5;
					// R[i][j] /= c[i][j];
					// G[i][j] /= c[i][j];
					// B[i][j] /= c[i][j];
				}
			}

			cout << -1 << '\n' << 0 << '\n';
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					cout << R[i][j] << '\n' << G[i][j] << '\n' << B[i][j] << '\n';
				}
			}
		}
	}

	cout.flush();
	return 0;
}
