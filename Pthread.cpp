// CPP Program to find sum of array
#include <iostream>
#include <pthread.h>
#include <chrono>
#include <time.h> 
using namespace std::chrono;
using namespace std;

int a[100000];
int sum[20] = { 0 };
int part = 0;

void* sum1(void* arg)
{
	int thread_part = part++;
	for (int i = thread_part * 100000; i < (thread_part + 1) * 100000; i++)
        sum[thread_part] += a[i];
	return 0;
}

void* sum2(void* arg)
{
	int thread_part = part++;

	for (int i = thread_part * 100000/2; i < (thread_part + 1) * 100000/2; i++)
        sum[thread_part] += a[i];
	return 0;
}

void* sum4(void* arg)
{
	int thread_part = part++;

	for (int i = thread_part * 100000/4; i < (thread_part + 1) * 100000/4; i++)
        sum[thread_part] += a[i];
	return 0;
}

void* sum5(void* arg)
{
	int thread_part = part++;

	for (int i = thread_part * 100000/5; i < (thread_part + 1) * 100000/5; i++)
        sum[thread_part] += a[i];
	return 0;
}

void* sum10(void* arg)
{
	int thread_part = part++;

	for (int i = thread_part * 100000/10; i < (thread_part + 1) * 100000/10; i++)
        sum[thread_part] += a[i];
	return 0;
}

void* sum20(void* arg)
{
	int thread_part = part++;

	for (int i = thread_part * 100000/20; i < (thread_part + 1) * 100000/20; i++)
        sum[thread_part] += a[i];
	return 0;
}
// Driver Code
int main()
{
	int tc = 1;
	
    


	pthread_t threads[20];

	int avgs[6] = {0};

	for(int i =0;i<3;i++){
		switch(i){
			case 0:
			srand(reinterpret_cast<unsigned long>(a));
				cout<<"rand seed 1"<<endl<<"==============================="<<endl;
			break;
			case 1:
			cout<<"rand seed 2"<<endl<<"==============================="<<endl;
				srand(0);
			break;
			case 2:
			cout<<"rand seed 3"<<endl<<"==============================="<<endl;
				srand(time(NULL));
			break;
		}
	
	for(int i=0;i<100000;i++)
        a[i]=rand()%100000;
	

	int avg = 0;
	for(int i = 0; i<3;i++){
		auto start = high_resolution_clock::now();
		for (int i = 0; i < 1; i++)
			pthread_create(&threads[i], NULL, sum1, (void*)NULL);

		
		for (int i = 0; i < 1; i++)
			pthread_join(threads[i], NULL);


		int total_sum = 0;
		for (int i = 0; i < 1; i++)
			total_sum += sum[i];
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);
		part = 0;
		cout << "sum 1:  " << total_sum << " || time: "<<  duration.count() << " ____ ";
		avg += duration.count();
		total_sum = 0;
		for (int i = 0; i < 20; i++){
			sum[i]=0;
		}
		
	}
	cout<<endl;
	avgs[0]+=avg/3;
	cout << "avg time 1: "<<avg/3<<endl;
	avg=0;
	
	
//-----------------------------------------------------------------------------------------------
	avg = 0;
	tc = 2;
	for(int i = 0; i<3;i++){
		auto start = high_resolution_clock::now();
		for (int i = 0; i < tc; i++)
			pthread_create(&threads[i], NULL, sum2, (void*)NULL);

		
		for (int i = 0; i < tc; i++)
			pthread_join(threads[i], NULL);


		int total_sum = 0;
		for (int i = 0; i < tc; i++)
			total_sum += sum[i];
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);
		part = 0;
		cout << "sum 2:  " << total_sum << " || time: "<<  duration.count() << " ____ ";
		avg += duration.count();
		total_sum = 0;
		for (int i = 0; i < 20; i++){
			sum[i]=0;
		}

	}
	cout<<endl;
	avgs[1]+=avg/3;
	cout << "avg time 2: "<<avg/3<<endl;
	avg=0;

//--------------------------------------------------------------------------------------------------

	avg = 0;
	tc = 4;
	for(int i = 0; i<3;i++){
		auto start = high_resolution_clock::now();
		for (int i = 0; i < tc; i++)
			pthread_create(&threads[i], NULL, sum4, (void*)NULL);

		
		for (int i = 0; i < tc; i++)
			pthread_join(threads[i], NULL);


		int total_sum = 0;
		for (int i = 0; i < tc; i++)
			total_sum += sum[i];
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);
		part = 0;
		cout << "sum 4:  " << total_sum << " || time: "<<  duration.count() << " ____ ";
		avg += duration.count();
		total_sum = 0;
		for (int i = 0; i < 20; i++){
			sum[i]=0;
		}

	}
	cout<<endl;
	avgs[2]+=avg/3;
	cout << "avg time 4: "<<avg/3<<endl;
	avg=0;
//--------------------------------------------------------------------------------------------------

	avg = 0;
	tc = 5;
	for(int i = 0; i<3;i++){
		auto start = high_resolution_clock::now();
		for (int i = 0; i < tc; i++)
			pthread_create(&threads[i], NULL, sum5, (void*)NULL);

		
		for (int i = 0; i < tc; i++)
			pthread_join(threads[i], NULL);


		int total_sum = 0;
		for (int i = 0; i < tc; i++)
			total_sum += sum[i];
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);
		part = 0;
		cout << "sum 5:  " << total_sum << " || time: "<<  duration.count() << " ____ ";
		avg += duration.count();
		total_sum = 0;
		for (int i = 0; i < 20; i++){
			sum[i]=0;
		}

	}
	cout<<endl;
	avgs[3]+=avg/3;
	cout << "avg time 5: "<<avg/3<<endl;
	avg=0;
//--------------------------------------------------------------------------------------------------

	avg = 0;
	tc = 10;
	for(int i = 0; i<3;i++){
		auto start = high_resolution_clock::now();
		for (int i = 0; i < tc; i++)
			pthread_create(&threads[i], NULL, sum10, (void*)NULL);

		
		for (int i = 0; i < tc; i++)
			pthread_join(threads[i], NULL);


		int total_sum = 0;
		for (int i = 0; i < tc; i++)
			total_sum += sum[i];
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);
		part = 0;
		cout << "sum 10:  " << total_sum << " || time: "<<  duration.count() << " ____ ";
		avg += duration.count();
		total_sum = 0;
		for (int i = 0; i < 20; i++){
			sum[i]=0;
		}

	}
	cout<<endl;
	avgs[4]+=avg/3;
	cout << "avg time 10: "<<avg/3<<endl;
	avg=0;
//--------------------------------------------------------------------------------------------------

	avg = 0;
	tc = 20;
	for(int i = 0; i<3;i++){
		auto start = high_resolution_clock::now();
		for (int i = 0; i < tc; i++)
			pthread_create(&threads[i], NULL, sum20, (void*)NULL);

		
		for (int i = 0; i < tc; i++)
			pthread_join(threads[i], NULL);


		int total_sum = 0;
		for (int i = 0; i < tc; i++)
			total_sum += sum[i];
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);
		part = 0;
		cout << "sum 20:  " << total_sum << " || time: "<<  duration.count() << " ____ ";
		avg += duration.count();
		total_sum = 0;
		for (int i = 0; i < 20; i++){
			sum[i]=0;
		}

	}
	cout<<endl;
	avgs[5]+=avg/3;
	cout << "avg time 20: "<<avg/3<<endl;
	avg=0;
//--------------------------------------------------------------------------------------------------

	}
	
	for( int x : avgs){
		cout<< "avg: "<<x/3<<endl;
	}


	return 0;
}
