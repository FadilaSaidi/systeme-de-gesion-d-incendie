import cv2

# Create a HOG (Histogram of Oriented Gradients) person detector
hog = cv2.HOGDescriptor()
hog.setSVMDetector(cv2.HOGDescriptor_getDefaultPeopleDetector())

# Open the webcam
cap = cv2.VideoCapture('demo.mp4')

def rescale_frame(frame, percent=75):
    width = int(frame.shape[1] * percent/ 100)
    height = int(frame.shape[0] * percent/ 100)
    dim = (width, height)
    return cv2.resize(frame, dim, interpolation =cv2.INTER_AREA)

# Check success
if not cap.isOpened():
    raise Exception("Could not open video device")

while True:
    
    # Read a frame from the webcam
    ret, frame = cap.read()
    

    # Detect people in the frame
    boxes, weights = hog.detectMultiScale(frame, winStride=(8,8))

    # Draw bounding boxes around detected people
    for (x, y, w, h) in boxes:
        cv2.rectangle(frame, (x, y), (x+w, y+h), (0, 0, 255), 2)
        
	# describe the type of font
	# to be used.
    font = cv2.FONT_HERSHEY_SIMPLEX

	# Use putText() method for
	# inserting text on video
    if len(boxes) > 0:
        cv2.putText(frame,
                    'Someone is present',
                    (10, 25),
                    font, 1,
                    (255, 255, 0),
                    2,
                    cv2.LINE_4)
    else:
        cv2.putText(frame,
                    'No one is here',
                    (10, 25),
                    font, 1,
                    (255, 255, 0),
                    2,
                    cv2.LINE_4)

    # Display the frame
    frame = rescale_frame(frame, percent=150)
    cv2.imshow('Webcam', frame)

    # Check if the user pressed 'q' to quit
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break       

# Release the webcam and close all windows
cap.release()
cv2.destroyAllWindows()