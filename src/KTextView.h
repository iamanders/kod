@class KDocument;

@interface KTextView : NSTextView {
  BOOL automaticallyKeepsIndentation_;
  BOOL tabControlsIndentationLevel_;

  // kconf value "editor/text/newline" (defaults to LF)
  NSString *newlineString_;

  // kconf value "editor/text/indentation" (defaults to 2xSP)
  NSString *indentationString_;
  
  NSMutableSet *autocompleteWords_;
}

// The parent document
@property(readonly) KDocument *document;

/*!
 * If enabled and when creating a new line; that line will be indented to the
 * same level as the line at which the selection begins are at.
 * Controlled by the kconf value "editor/indent/newline" (defaults to YES)
 */
@property BOOL automaticallyKeepsIndentation;

/*!
 * Enable [TAB=indent] & [TAB+SHIT=dedent] current selected lines.
 * If enabled, pressing TAB will never insert a TAB character.
 * If disabled, pressing TAB inserts a regular TAB character.
 * Controlled by the kconf value "editor/indent/tabkey" (defaults to YES)
 */
@property BOOL tabControlsIndentationLevel;

// Invoked when a proprety of kconf changed
- (void)configurationValueDidChange:(NSNotification*)notification;

// Inrease the indentation level for the currently selected text
- (void)increaseIndentation;

// Decrease the indentation level for the currently selected text
- (void)decreaseIndentation;

@end
