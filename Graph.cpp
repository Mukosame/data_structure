template <typename Tv, typename Te> class Graph{//�������͡�������
private:
 void reset(){//���ж��㡢�ߵĸ�����Ϣ��λ
 for (int i = 0; i < n; i++){//����
    status(i) = UNDISCOVERED; dTime(i) = fTime(i) = -1;
    parent(i) = -1; priority(i) = INT_MAX;	
	for (int j = 0; j < n; j++)//��
	  if (exists(i, j)) status(i, j) = UNDETERMINED;
	}
}
public: //����������߲�����ͼ�㷨���������ʵ�֣��ӿڱ���ͳһ
}//Graph
