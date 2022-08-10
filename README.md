# cub3d
+ 레이캐스팅을 사용하여, 2D맵을 3D로 화면에 구현
+ OpenGL 기반 라이브러리인 minilibx 사용

## 실행화면
![cub3d](https://user-images.githubusercontent.com/56538203/183872675-a25117d4-67f2-4e60-a3c6-d562f9f520aa.gif)

## start
```
  make bonus
  ./cub3D proper_map.cub
```

## key
+ 이동: wasd
+ 카메라 회전: ←, →, 마우스

## map file
+ NO, SO, WE, EA : 동서남북에 해당하는 벽 텍스처 이미지파일의 경로
+ F, C : 바닥과 천장 색의 RGB 값
+ 1 : 벽
+ 0 : 빈 공간
+ N (또는) S, W, E : 플레이어의 위치 (N S W E는 플레이어가 바라보는 방향)
