#import "@preview/cetz:0.4.2"

#cetz.canvas({
  import cetz.draw: *
  content(
    (0, 0),
    (8, 2),
    box(
      par()[NODE begin \
      scanf("%d", &arg);],
      stroke: 1pt,
      width: 100%,
      height: 100%,
      inset: 1em,
    ),
  )
})
