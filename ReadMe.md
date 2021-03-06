#Data_Struct

1.정의

a) 자료 구조란?

	- 대량의 데이터를 효율적으로 관리하기 위해, 데이터를 저장 및 정렬하는 방식이다.
	
	- 데이터를 어떤 방식으로 저장하고 정렬하느냐에 따라 추출 방식 등 데이터를 처리
	및 조작하는데 필요한 코드가 달라진다.

2.자료 구조

a) 배열 (Array)

	- 한가지 데이터 타입의 데이터를 순차적으로 저장 및 정렬하는 자로 구조

	-장점 : 각 데이터마다 index를 부여하여 데이터 검색에 용이하다.

	-단점 : 크기가 고정적이고 데이터가 삭제되면 배열 전체의 데이터를 재정렬 해야 한다.

b) 큐 (Queue) 
	

	-First In, First Out 방식으로 데이터를 저장 및 정렬하는 자료구조.

	-FIFO 방식으로 인해 데이터 삭제시, 재정렬이 필요 없다.

	-운영체제(OS)에서 프로세스 스케줄링 방식을 구현하기 위해 사용된다.

c) 스택 (Stack)

	
	-Last In, First Out으로 데이터를 쌓는 방식으로 저장 및 정렬하는 자료구조.
	
	-LIFO 방식으로 인해, 데이터의 저장 및 검색 속도가 빠르다.
	
	-저장될 수 있는 데이터의 최대 개수를 미리 정해주어야 한다. 즉 저장공간의 낭비가 발생.
	
	-프로세스 실행 구조의 기본으로 사용되는 자료구조이다.

d) 연결리스트 (Linked List) 
	
	-배열의 단점이 보완된 형태의 자료구조로, 크기가 가변적인 배열
	
	-크기의 가변성을 구현하기 위해 노드와 포인터를 사용하여 데이터를 저장 및 연결한다.
	
	-노드: 데이터의 저장 단위로, 데이터 값과 포인터(주소 값)를 한 쌍으로 구성한다.
	
	-포인터 : 각 노드의 위치정보를 의미한다.
	
	-포인터를 위한 저장 공간이 따로 필요하다.

	-포인터를 이용해 연결 노드를 찾는 시간이 필요하다. (접근 속도가 느리다)

	-데이터가 삭제되면 삭제된 데이터의 이전과 다음 데이터의 연결을 재구성 해야된다.

f) 트리 (Tree)

	-노드와 브렌치를 이용하여 구성한 자료구조로, 사이클이 없는 그래프와 같다.
	
	-트리를 기반한 이진트리를 이용하여 탐색 알고리즘 구현에 사용된다.

g) 그래프 (Graph)

	-그래프는 정점과 간선으로 이루어진 자료구조 이다.

	-정점(vertex)과 정점간의 관계를 연결하는 선(edge)과 함께 표현하는 조적도이다.
	
	-다양한 그래프가 존재하며 트리 또한 그래프의 일종이다.
