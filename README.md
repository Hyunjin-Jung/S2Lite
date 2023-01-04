# S2Lite

2021 세종대 소프트웨어설계기초 001분반 11조 - 임경태, 오창묵, 조윤희, 정현진 최종 결과물

**타자 연습 방식을 이용한 RPG 게임**


### 실행 방법
* Source 폴더의 코드를 다운 받은 후 메인.c를 실행한다. 
* 11조_실행파일.exe를 다운 받아 실행한다. 

### 게임 설명
몬스터를 잡아 돈과 경험치를 얻을 수 있다. 레벨을 올려 스킬을 얻고, 보스를 잡으면 게임이 클리어된다. 


* 이동 방법

![image](https://user-images.githubusercontent.com/67624124/210494030-6bdd3e7d-d3c4-4694-8fa1-c3a3308f508e.png)


* 공격 방식
 <img src="https://user-images.githubusercontent.com/67624124/210494354-c6665469-8ed9-4ece-a53b-996ceb6d5393.png" width="50%" height="50%"/>
 <img src="https://user-images.githubusercontent.com/67624124/210494385-a375989b-709e-4a1e-8e78-364679d7c76b.png" width="50%" height="50%"/>

공격 방식을 선택 후 제시된 문장을 입력한다. 문장을 정확히 입력하면 공격이 성공한다. 


* 속성
 <img src="https://user-images.githubusercontent.com/67624124/210495408-2fde4640-513a-4b98-b78c-125eeaa82f77.png" width="50%" height="50%"/>
플레이어의 처음 속성은 무속성이다. 속성이 있는 스킬을 사용하면 해당 속성으로 변화한다. 


* 스킬 
 <img src="https://user-images.githubusercontent.com/67624124/210495303-9d71b87e-e646-440a-a0f8-59f2d5cb555f.png" width="50%" height="50%"/>
레벨에 따라 3가지 스킬 중 하나를 선택하여 배울 수 있다. 맨 위가 얼음 속성, 중간이 화염 속성, 밑이 전기 속성 스킬이다. 


* 장비
 <img src="https://user-images.githubusercontent.com/67624124/210496041-e7b6fc00-1ef5-4374-a1ae-cd9bad599859.png" width="50%" height="50%"/>
장비 종류 : HAT, ROBE, SHOES, WEAPON, BRACELET 

장비 등급 : 노말, 레어, 에픽, 유니크, 레전더리

장비 레벨 : 1 ~ 10

장비 강화는 장비 강화 창에서 강화의 돌과 돈을 사용해 가능하다. 


* 아이템
 <img src="https://user-images.githubusercontent.com/67624124/210496165-b84b2fdc-86d3-44c5-9493-b63b230aae40.png" width="50%" height="50%"/>
아이템 종류 : HP포션, MP포션, ALL포션, EXP포션, 골드박스

아이템 상점에서 돈으로 구입 가능하다. 아이템은 전투 시 사용할 수 있다. 

* 몬스터 
 <img src="https://user-images.githubusercontent.com/67624124/210496272-a6af5a13-ac3a-4bd7-9b89-47332043d6ef.png" width="50%" height="50%"/>
  <img src="https://user-images.githubusercontent.com/67624124/210496286-ed33f36d-dbdb-475f-83ef-8cdf714575a5.png" width="50%" height="50%"/>

일반 몬스터는 웜과 스파이웨어로 구분할 수 있다. 
```
웜(동그라미) : 위아래 이동, 체력 특화 
스파이웨어(세모) : 좌우 이동, 공격 특화
속성에 따라 색 변화 (얼음-하늘색, 화염-빨간색, 전기-노란색)
```

플레이어보다 레벨이 높은 몬스터는 다가가면 플레이어를 따라온다. 속성이 표시되지 않으며 흰색 다이아몬드로 표시된다. 

보스 몬스터는 3가지 속성을 모두 가지고 있다. 속성이 변화함에 따라 공격 패턴이 변화한다. 


