import cv
 
cv.NamedWindow("w1", cv.CV_WINDOW_AUTOSIZE)
camera_index = 0
capture = cv.CaptureFromCAM(camera_index)
 
gx = gy = 1
grayscale = blur = canny = False
 
def repeat():
    global capture #declare as globals since we are assigning to them now
    global camera_index
    global gx, gy, grayscale, canny, blur
    frame = cv.QueryFrame(capture)
    # import pdb; pdb.set_trace()
 
    if grayscale:
        gray = cv.CreateImage(cv.GetSize(frame), frame.depth, 1)
        cv.CvtColor(frame, gray, cv.CV_RGB2GRAY)
        frame = gray
 
    if blur:
        g = cv.CreateImage(cv.GetSize(frame), cv.IPL_DEPTH_8U, frame.channels)
        cv.Smooth(frame, g, cv.CV_GAUSSIAN, gx, gy)
        frame = g
 
    if grayscale and canny:
        c = cv.CreateImage(cv.GetSize(frame), frame.depth, frame.channels)
        cv.Canny(frame, c, 10, 100, 3)
        frame = c
    cv.ShowImage("w1", frame)
 
    c = cv.WaitKey(10)
    if c==ord('='): #in "n" key is pressed while the popup window is in focus
        gx += 2
        gy += 2
    elif c == ord('-'):
        gx = max(1, gx-2)
        gy = max(1, gy-2)
    elif c == ord('x'):
        gx += 2
    elif c == ord('X'):
        gx = max(1, gx-2)
    elif c == ord('q'):
        exit(0)
 
    elif c == ord('b'):
        blur = not blur
    elif c == ord('g'):
        grayscale = not grayscale
    elif c == ord('c'):
        canny = not canny
 
while True:
    repeat()